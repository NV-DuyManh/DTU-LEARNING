describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 22: a=1, b=50, c=1 <=> 1x² + 50x + 1 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('1');
    cy.get('#term-b').clear().type('50');
    cy.get('#term-c').clear().type('1');
    cy.get('#root-1').should('have.value', '-0.02');
    cy.get('#root-2').should('have.value', '-49.98');
    cy.get('#delta').should('have.value', '2496.00');
  });
});