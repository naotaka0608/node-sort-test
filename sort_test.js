var addon = require( './build/Release/addon' );
const microtime = require("microtime");

let array_value = 
[
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
];


// JavaScriotでクイックソートを作成

{
    let test1 = Array.from(array_value);
    // console.info(test1);

    const start1 = microtime.now();

    QuickSort(test1, 0, test1.length-1);
    
    console.info(microtime.now() - start1);    
    // console.info(test1);
}


// array.sort()

{
    let test2 = Array.from(array_value);
    // console.info(test2);

    const start2 = microtime.now();

    test2.sort((a, b) => a - b);

    console.info(microtime.now() - start2);
    // console.info(test2);
}


// JavaScript -> C++

{
    let test3 = Array.from(array_value);
    // console.info(test3);

    const start2 = microtime.now();

    let test4 = addon.quickSortJS(test3, 0, test3.length-1);

    console.info(microtime.now() - start2);
    // console.info(test4);
}


// JavaScriptでQuickSortをベタ書き
function QuickSort(array, left, right){

    let i, j;
    let pivot;

    i = left;
    j = right;

    pivot = array[Math.floor((left + right)/2)];

    while(true){

        while(array[i] < pivot) i++;

        while(pivot < array[j]) j--;

        if(i >= j) break;

        Swap(array, i, j);

        i++;
        j--;

    }

    if(left < (i-1)) QuickSort(array, left, (i-1));

    if((i+1) < right) QuickSort(array, (j+1), right);

}

function Swap(x, i ,j){
    let temp;
    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
}