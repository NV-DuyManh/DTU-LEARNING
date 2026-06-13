describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 10: a=50, b=-9999, c=50 <=> 50x² - 9999x + 50 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('50');
    cy.get('#term-b').clear().type('-9999');
    cy.get('#term-c').clear().type('50');
    cy.get('#root-1').should('have.value', '199.97');
    cy.get('#root-2').should('have.value', '0.01');
    cy.get('#delta').should('have.value', '99970001.00');
  });
});