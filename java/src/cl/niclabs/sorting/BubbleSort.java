package src.cl.niclabs.sorting;

/**
 * Created by practicasti on 03-11-2016.
 */
public class BubbleSort extends Sort {

    @Override
    public void Sort(int[] arr) {
        for (int j = arr.length - 1; j >= 0; j--) {
            for (int i = 0; i < j; i++) {
                if (arr[i]>arr[i+1]){
                    swap(arr, i, i+1);
                }
            }
        }
    }
}
