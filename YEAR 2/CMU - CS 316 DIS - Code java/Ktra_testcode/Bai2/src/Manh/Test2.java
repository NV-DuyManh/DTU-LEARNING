package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.Calculator2;

class Test2 {

	@Test
    void testResultValue() {
        Calculator2 calc = new Calculator2();
        calc.number1 = 5;
        calc.number2 = 3;
        calc.sub();
        assertEquals(2, calc.result);
    }

    @Test
    void testNumberLargerThanMaxInt() {
        Calculator2 calc = new Calculator2();
        calc.number1 = Integer.MAX_VALUE;
        calc.number2 = -1;
        assertThrows(ArithmeticException.class, calc::sub);
    }

    @Test
    void testNumberSmallerThanMinInt() {
        Calculator2 calc = new Calculator2();
        calc.number1 = Integer.MIN_VALUE;
        calc.number2 = 1;
        assertThrows(ArithmeticException.class, calc::sub);
    }
}
