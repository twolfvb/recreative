package cl.niclabs.test;

import junit.framework.TestCase;
import org.junit.Assert;
import org.junit.Test;
import src.cl.niclabs.sorting.InsertSort;

import java.awt.*;

/**
 * Created by practicasti on 27-10-2016.
 */
public class InsertSortTest extends TestCase{
    private int[] testArray;
    InsertSort sort;

    @Override
    protected void setUp(){
        this.sort = new InsertSort();
    }

    @Override
    protected void tearDown(){
        this.testArray = null;
        this.sort = null;
    }

    @Test
    public void testInsertSort(){
        //Arrange
        this.testArray = new int[] {5, 2, 4, 6, 1, 3};
        //Act
        this.sort.Sort(testArray);
        //Assert
        for (int i = 1; i < testArray.length; i++) {
            Assert.assertTrue(testArray[i-1] < testArray[i]);
        }
    }

    @Test
    public void testAlreadyOrdered(){
        //Arrange
        testArray = new int[] {1, 2, 3, 4, 5, 6};
        //Act
        sort.Sort(testArray);
        //Assert
        for (int i = 1; i < testArray.length; i++) {
            Assert.assertTrue(testArray[i-1] < testArray[i]);
        }

    }
}
