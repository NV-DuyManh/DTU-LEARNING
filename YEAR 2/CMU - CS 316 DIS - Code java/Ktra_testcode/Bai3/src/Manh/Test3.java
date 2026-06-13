package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.Calculator3;

class Test3 {

	 @Test
	    void testResultValue() {
	        Calculator3 calc = new Calculator3(2, 3);
	        assertEquals(6, calc.mul());
	    }

	    @Test
	    void testNumberLargerThanMaxInt() {
	        Calculator3 calc = new Calculator3(Integer.MAX_VALUE, 2);
	        assertThrows(ArithmeticException.class, calc::mul);
	    }

	    @Test
	    void testNumberSmallerThanMinInt() {
	        Calculator3 calc = new Calculator3(Integer.MIN_VALUE, -1);
	        assertThrows(ArithmeticException.class, calc::mul);
	    }

}
