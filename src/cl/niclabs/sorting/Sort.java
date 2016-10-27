package src.cl.niclabs.sorting;

/**
 * Created by practicasti on 27-10-2016.
 */
public abstract class Sort {
    public abstract void Sort(int[] arr);
    public static void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
