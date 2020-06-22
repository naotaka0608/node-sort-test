#include <napi.h>
#include <iostream>

#include "./myLib/sortLib.h"

using namespace Napi;

Napi::Array QuickSortJS( const CallbackInfo& info ) {

    Napi::Env env = info.Env();
    Array array_val = info[ 0 ].As<Array>();
    const int max_value = array_val.Length();

    int *array = new int[max_value];
    
    for(int i = 0; i<max_value; i++){
      Napi::Value v = array_val[i];
      if (v.IsNumber())
      {
        array[i] = (int)v.As<Napi::Number>();
      }
    }

    int start, end;
    start = info[ 1 ].As<Number>().DoubleValue();
    end = info[ 2 ].As<Number>().DoubleValue();

    SortLib sortLib;
    sortLib.QuickSort(array, start, end);
    
    Napi::Array outputArray = Napi::Array::New(env, max_value);
    for (int i = 0; i < max_value; i++) {
        outputArray[i] = Napi::Number::New(env, double(array[i]));
    }

    delete[] array;

    return outputArray;
    
}



/*
void QuickSortJS( const CallbackInfo& info ) {

    // Env env = info.Env();

    // if ( info.Length() < 2 ) {
    //     TypeError::New( env, "Wrong number of arguments" ).ThrowAsJavaScriptException();
    //     return env.Null();
    // }

    // if ( !info[ 0 ].IsNumber() || !info[ 1 ].IsNumber() ) {
    //     TypeError::New( env, "Wrong arguments" ).ThrowAsJavaScriptException();
    //     return env.Null();
    // }
    

    SortLib sortLib;

    const int max_value = 100;

    int array[max_value] = 
	{ 
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
		3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
	};
    int start, end;

    start = 0;
    end = max_value-1;

    // for(int i=0; i<max_value; i++){
    //     std::cout << array[i];
    // }
    // std::cout << std::endl;
    // const clock_t start_t = clock();
    
    sortLib.QuickSort(array, start, end);

    // const clock_t end_t = clock();

    // std::cout << "C++ duration = " << (double) (end_t - start_t) / CLOCKS_PER_SEC << "sec.\n";

    // for(int i=0; i<max_value; i++){
    //     std::cout << array[i];
    // }
    // std::cout << std::endl;

}
*/


Object Init( Env env, Object exports ) {
    exports.Set( String::New( env, "quickSortJS" ), Function::New( env, QuickSortJS ) );
    
    return exports;
}

NODE_API_MODULE( addon, Init )