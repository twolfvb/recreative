package src.cl.niclabs.sorting;

/**
 * Created by practicasti on 03-11-2016.
 */

public class QuickSort extends Sort {

    @Override
    public void Sort(int[] arr) {
        quickSort(arr, 0, arr.length-1);
    }

    public void quickSort(int[] arr, int low, int high){
        int i = low, j = high;
        int pivot = arr[low + (high-low)/2];
        while (i <= j){
            while(arr[i] < pivot){
                i++;
            }
            while(arr[j] > pivot){
                j--;
            }
            if( i <= j ){
                swap(arr, i, j);
                i++;
                j--;
            }
        }

        if (low < j) quickSort(arr, low, j);
        if (i < high)quickSort(arr, i, high);

    }
}
