describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 15: a=50, b=50, c=-10001 <=> 50x² + 50x - 10001 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('50');
    cy.get('#term-b').clear().type('50');
    cy.get('#term-c').clear().type('-10001');
    cy.get('#root-1').should('have.value', 'Infinity');
    cy.get('#root-2').should('have.value', 'Infinity');
    cy.get('#delta').should('have.value', 'Infinity');
  });
});