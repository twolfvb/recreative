package src.cl.niclabs.playtest;

import src.cl.niclabs.sorting.BubbleSort;

/**
 * Created by twolf on 03-11-2016.
 */
public class LiveTest {
    static public void main(String[] args){
        int[] testArray  = new int[] {5, 2, 4, 6, 1, 3};
        for (int i = 0; i < testArray.length; i++) {
            System.out.print(testArray[i]);
        }
        System.out.println("");
        BubbleSort sort = new BubbleSort();
        sort.Sort(testArray);
        for (int i = 0; i < testArray.length; i++) {
            System.out.print(testArray[i]);
        }
    }
}
