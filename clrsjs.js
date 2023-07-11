function insertionSort(arr) {
  for (let i = 1; i < arr.length; i++) {
    let k = arr[i]; // k remains unchanged
    let j = i - 1;

    while (j >= 0 && arr[j] > k) {
      arr[j + 1] = arr[j];

      j = j - 1;
    }

    arr[j + 1] = k;
  }

  return arr;
}

console.log(insertionSort([1, 23, 4, 45, 23, 13]));
