describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 13: a=50, b=10000, c=50 <=> 50x² + 10000x + 50 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('50');
    cy.get('#term-b').clear().type('10000');
    cy.get('#term-c').clear().type('50');
    cy.get('#root-1').should('have.value', '-199.99');
    cy.get('#root-2').should('have.value', '-0.01');
    cy.get('#delta').should('have.value', '99990000.00');
  });
});