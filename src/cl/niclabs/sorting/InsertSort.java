package src.cl.niclabs.sorting;

/**
 * Created by practicasti on 27-10-2016.
 */
public class InsertSort extends Sort{

    @Override
    public void Sort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int j = i;
            while(j > 0){
                if (arr[j] < arr[j-1]){
                    Sort.swap(arr, j, j-1);
                }
                j--;
            }
        }
    }


}
