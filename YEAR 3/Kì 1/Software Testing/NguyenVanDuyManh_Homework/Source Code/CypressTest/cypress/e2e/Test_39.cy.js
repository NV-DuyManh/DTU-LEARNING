describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 39: a=1e-50, b=2, c=1 <=> 1e-50x² + 2x + 1 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('1e-50');
    cy.get('#term-b').clear().type('2');
    cy.get('#term-c').clear().type('1');
    cy.get('#root-1').should('have.value', '-0.50');
    cy.get('#root-2').should('have.value', '-2.00e+50');
    cy.get('#delta').should('have.value', '4.00');
  });
});