package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.Calculator4;

class Test4 {

	@Test
	void testResultValue() {
	    Calculator4 calc = new Calculator4();
	    calc.setNumber1(10);
	    calc.setNumber2(2);
	    assertEquals(5, calc.div()); // Kết quả chính xác của phép chia.
	}

	@Test
	void testDivisionByZero() {
	    Calculator4 calc = new Calculator4();
	    calc.setNumber1(10);
	    calc.setNumber2(0);
	    assertThrows(ArithmeticException.class, calc::div); // Phép chia cho 0 ném ra lỗi.
	}
	@Test
	void testReturnFloat() {
	    Calculator4 calc = new Calculator4();
	    calc.setNumber1(5);
	    calc.setNumber2(2);
	    assertEquals(2, calc.div()); // Vì `div()` hiện trả về `int`, kết quả sẽ là phần nguyên.
	}



}
