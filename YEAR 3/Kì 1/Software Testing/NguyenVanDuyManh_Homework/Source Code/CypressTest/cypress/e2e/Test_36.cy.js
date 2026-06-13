describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 36: a=1, b=5, c="3.14" <=> 1x² + 5x + "3.14" = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('1');
    cy.get('#term-b').clear().type('5');
    cy.get('#term-c').clear().type('3.14');
    cy.get('#root-1').should('have.value', '-4.26');
    cy.get('#root-2').should('have.value', '-0.74');
    cy.get('#delta').should('have.value', '12.44');
  });
});