#include <napi.h>
#include <iostream>
#include <time.h>

#include "./myLib/sortLib.h"

using namespace Napi;


Napi::Array QuickSortJS( const CallbackInfo& info ) {

    Napi::Env env = info.Env();

    // 引数 1
    Array array_val = info[ 0 ].As<Array>();
    const int max_value = array_val.Length();

    int *array = new int[max_value];
    
    // int配列に移し替え
    for(int i=0; i<max_value; i++){
        Napi::Value v = array_val[i];
        if (v.IsNumber()){
            array[i] = (int)v.As<Napi::Number>();
        }
    }

    // 引数 2 と 3
    int start, end;
    start = info[ 1 ].As<Number>().Int32Value();
    end = info[ 2 ].As<Number>().Int32Value();

    // ソート
    SortLib sortLib;
    sortLib.QuickSort(array, start, end);
    
    // Napi配列に移し替え
    Napi::Array outputArray = Napi::Array::New(env, max_value);
    for (int i=0; i<max_value; i++) {
        outputArray[i] = Napi::Number::New(env, array[i]);
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

    const int max_value = 200;

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
        
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10, 
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10,
        3, 7, 2, 4, 6, 1, 9, 8, 5, 10, // 200
	};

    int start, end;
    start = 0;
    end = max_value-1;

    // ソート前
    // for(int i=0; i<max_value; i++){
    //     std::cout << array[i];
    // }
    // std::cout << std::endl;

    // const clock_t start_t = clock();
    
    sortLib.QuickSort(array, start, end);

    // const clock_t end_t = clock();

    // std::cout << "C++ duration = " << (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000.0 / max_value << "sec.\n";

    // ソート後
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