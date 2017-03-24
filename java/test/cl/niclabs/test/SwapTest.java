package cl.niclabs.test;
import junit.framework.TestCase;
import org.junit.Assert;
import org.junit.Test;
import src.cl.niclabs.sorting.Sort;

/**
 * Created by twolf on 27-10-2016.
 */
public class SwapTest extends TestCase{

    private int[] testArray;

    @Override
    protected void setUp(){
        testArray = new int[] {1, 2, 3};
    }

    @Test
    public void testSwap() throws Exception {
        //Act
        Sort.swap(testArray,0,2);
        //Assert
        Assert.assertEquals(3, testArray[0]);
        Assert.assertEquals(1, testArray[2]);
    }
}
