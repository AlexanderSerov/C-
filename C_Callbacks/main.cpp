#include <iostream>
#include <functional>

// 1) Try to use heap lambdas - FAILED. Can't convert capture lambda pointer to C style function pointer
// 2) Try to use std::function::target - FAILED
// 3) Try to use that Dima suggest - This approach is fail too because we can't convert std::bind to C function pointer
// ^ http://www.cplusplus.com/forum/general/92566/
// 4) From callback article: https://blog.mbedded.ninja/programming/languages/c-plus-plus/callbacks/
// 5) Use void* userdata - SUCCESS
// ^ Summary: We only can create a stateful callback to C api using global function wrapper.

using namespace std;

typedef void(*c_callback_t)(const int*);

struct C_interface {
    c_callback_t c_call = nullptr;
};

struct JNI_callback {
    std::function<void(const int*)> call;
};

void print () {
    cout << "Hello" << endl;
}

// ### Global callback wrapper
struct JNI_callback_wrap {
    void methodToCallback(const int* firstVar) const {
        cout << "Hello World and sum: " << *firstVar + (*secondVar) <<  endl;
    }
    int *secondVar;
};

static JNI_callback_wrap* myClassPtr;
static void cStyleWrapper(const int* num1) {
    return myClassPtr->methodToCallback(num1);
}

// ### Use void* userdata
using c_callback_data_t = void(*)(const int*, void*);
struct C_interface_WithData {
	void setCallback(c_callback_data_t c_call_in, void* userdata_in = nullptr) {
			c_call = c_call_in;
			userdata = userdata_in;
	}
	c_callback_data_t c_call = nullptr;
	void* userdata = nullptr;
};


int main()
{
	// ### Use void* userdata
	C_interface_WithData interface;

	int firstVar = 5;
	int secondVar = 4;
	int* secondVarPtr = &secondVar;

	{
		// In example below, potential userdata can be simplified from struct to primitive type.
		auto* j_callback = new JNI_callback_wrap{ secondVarPtr };

		interface.setCallback([](const int* var, void* userdata) {
			// This condition don't need actually because it on behalf of user to decide pass userdata or not
			if (userdata == nullptr) {
				cout << "Hello World and var: " << *var<<  endl;
			}
			else {
				auto *callback = reinterpret_cast<JNI_callback_wrap *>(userdata);
				callback->methodToCallback(var);
			}
		}, j_callback);
	}

	// Calling of caller
	// interface.c_call(&firstVar, interface.userdata);
	interface.c_call(&firstVar, nullptr);

    // ### Global callback wrapper
    /*C_interface interface;

    int firstVar = 5;
    int secondVar = 3;
    int* secondVarPtr = &secondVar;

    {
        auto* j_callback = new JNI_callback_wrap{ secondVarPtr };
        myClassPtr = j_callback;

        interface.c_call = &cStyleWrapper;
    }

    // Calling of caller
    interface.c_call(&firstVar);*/

    // ### Try to use std::function::target - FAILED!
    /*C_interface interface;

    int firstVar = 2;
    int secondVar = 3;
    int* secondVarPtr = &secondVar;

    // create heap callback and register it
    {
        auto lambda = [secondVarPtr](const int* var) { cout << "Hello World and sum: " << *var + (*secondVarPtr) <<  endl; };

        auto* j_callback = new JNI_callback();
        j_callback->call = lambda;

        // auto ert = &decltype(lambda)::operator();
        // j_callback->call.operator()(&firstVar);

        interface.c_call = *j_callback->call.target<c_callback_t>(); // Error: returns null
    }

    // Calling of caller
    interface.c_call(&firstVar);*/

    // ### Experimenting with func.target - it works with decltype(l)
    /*typedef void(*empty_func_t)();
    auto l = [] () { cout << "Hello" << endl; };
    std::function<void()> func = l;

    cout << typeid(&print).name() << endl;
    cout << typeid(empty_func_t).name() << endl;
    cout << func.target_type().name() << endl;

    empty_func_t ff = &print;

    auto* f = func.target<decltype(l)>();
    (*f)();*/

    // ### std::function on the heap
    /*auto* function = new std::function<void()> ([] () { cout << "Hello" << endl; });

    (*function)();
    delete function;*/

    // ### Pointer to non capture lambda
    /*typedef void(*pointer)();
    pointer p;
    {
        auto l = [](){ cout << "Hello" << endl; };
        p = l;
    }
    p();*/

}