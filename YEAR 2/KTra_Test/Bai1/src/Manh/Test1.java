package Manh;

import static org.junit.jupiter.api.Assertions.*;
import Nguyen.Calculator1;
import org.junit.jupiter.api.Test;

class Test1 {

	@Test
    public void testAddNormal() {
        Calculator1 c = new Calculator1();
        assertEquals(5, c.add(2, 3));
    }

    @Test
    public void testAddOverflow() { 	
        Calculator1 c = new Calculator1();
        int result = c.add(Integer.MAX_VALUE, 1);
        assertTrue(result < 0); // overflow ra số âm
    }

    @Test
    public void testAddUnderflow() {
        Calculator1 c = new Calculator1();
        int result = c.add(Integer.MIN_VALUE, -1);
        assertTrue(result > 0); // underflow ra số dương
    }

}
