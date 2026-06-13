describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 43: a="1 0", b=-11, c=10 <=> "1 0"x² - 11x + 10 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('1 0');
    cy.get('#term-b').clear().type('-11');
    cy.get('#term-c').clear().type('10');
    cy.get('#root-1').should('have.value', 'ERROR');
    cy.get('#root-2').should('have.value', 'ERROR');
    cy.get('#delta').should('have.value', 'ERROR');
  });
});