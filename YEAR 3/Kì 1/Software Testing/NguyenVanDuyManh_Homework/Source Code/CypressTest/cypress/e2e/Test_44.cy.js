describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 44: a="0x10", b=-17, c=1 <=> "0x10"x² - 17x + 1 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('0x10');
    cy.get('#term-b').clear().type('-17');
    cy.get('#term-c').clear().type('1');
    cy.get('#root-1').should('have.value', 'ERROR');
    cy.get('#root-2').should('have.value', 'ERROR');
    cy.get('#delta').should('have.value', 'ERROR');
  });
});