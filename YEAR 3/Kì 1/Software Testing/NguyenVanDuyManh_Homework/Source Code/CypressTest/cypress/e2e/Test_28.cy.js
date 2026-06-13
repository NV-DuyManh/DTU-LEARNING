describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 28: a=1, b=-9999, c=1 <=> 1x² - 9999x + 1 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('1');
    cy.get('#term-b').clear().type('-9999');
    cy.get('#term-c').clear().type('1');
    cy.get('#root-1').should('have.value', '9999.00');
    cy.get('#root-2').should('have.value', '0.00');
    cy.get('#delta').should('have.value', '99980000.00');
  });
});