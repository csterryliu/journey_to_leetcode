
var largestPerimeter = (A) => {
    // Sort the array first.
    // Notice: if we don't specify a compareFunction, the sorting of int will
    // be wrong.
    // for example:
    // a = [2, 7, 1, 19]
    // After a.sort(), it will be [1, 19, 2, 7]!
    // So we have to specify a compareFunction:

    // compareFunction(a,b) < 0
    // Then a comes before b in the answer.
    // compareFunction(a,b) > 0
    // Then b comes before a in the answer.
    // compareFunction(a,b) = 0
    // Then the order of a and b remains unchanged. 

    A.sort((a, b) => a - b);
    for (let i = A.length - 3; i >= 0; i -= 1) {
        if (A[i] + A[i+1] > A[i+2]) {
            return A[i] + A[i+1] + A[i+2];
        }
    }
    return 0;
}



const A = [2, 1, 2]
console.log(largestPerimeter(A));