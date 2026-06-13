describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 20: a=50, b=50, c=10000 <=> 50x² + 50x + 10000 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('50');
    cy.get('#term-b').clear().type('50');
    cy.get('#term-c').clear().type('10000');
    cy.get('#root-1').should('have.value', '-0.50 - 14.13i');
    cy.get('#root-2').should('have.value', '-0.50 + 14.13i');
    cy.get('#delta').should('have.value', '-1997500.00');
  });
});