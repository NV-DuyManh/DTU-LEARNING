describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 40: a=1, b=2, c="1,5" <=> 1x² + 2x + "1,5" = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('1');
    cy.get('#term-b').clear().type('2');
    cy.get('#term-c').clear().type('1,5');
    cy.get('#root-1').should('have.value', '-1.00 - 0.71i');
    cy.get('#root-2').should('have.value', '-1.00 + 0.71i');
    cy.get('#delta').should('have.value', '-2.00');
  });
});