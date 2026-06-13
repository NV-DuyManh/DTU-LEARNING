describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 41: a="1abc2", b=-3, c=2 <=> "1abc2"x² - 3x + 2 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('1abc2');
    cy.get('#term-b').clear().type('-3');
    cy.get('#term-c').clear().type('2');
    cy.get('#root-1').should('have.value', 'ERROR');
    cy.get('#root-2').should('have.value', 'ERROR');
    cy.get('#delta').should('have.value', 'ERROR');
  });
});