describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 37: a="9$", b=2, c=1 <=> "9$"x² + 2x + 1 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('9$');
    cy.get('#term-b').clear().type('2');
    cy.get('#term-c').clear().type('1');
    cy.get('#root-1').should('have.value', 'ERROR');
    cy.get('#root-2').should('have.value', 'ERROR');
    cy.get('#delta').should('have.value', 'ERROR');
  });
});