describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 11: a=50, b=0, c=50 <=> 50x² + 0x + 50 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('50');
    cy.get('#term-b').clear().type('0');
    cy.get('#term-c').clear().type('50');
    cy.get('#root-1').should('have.value', '0.00 - 1.00i');
    cy.get('#root-2').should('have.value', '0.00 + 1.00i');
    cy.get('#delta').should('have.value', '-10000.00');
  });
});