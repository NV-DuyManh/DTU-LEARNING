package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.SolveEquation;

class Test5 {

	@Test
	void testMultiRoots() {
	    SolveEquation equation = new SolveEquation();
	    equation.setNumber1(0);
	    equation.setNumber2(0);
	    assertEquals("Multi roots", equation.linearEquation());
	}

	@Test
	void testNoRoot() {
	    SolveEquation equation = new SolveEquation();
	    equation.setNumber1(0);
	    equation.setNumber2(5);
	    assertEquals("No root", equation.linearEquation());
	}

	@Test
	void testOneRoot() {
	    SolveEquation equation = new SolveEquation();
	    equation.setNumber1(2);
	    equation.setNumber2(5);
	    assertEquals("One root", equation.linearEquation());
	}


}
