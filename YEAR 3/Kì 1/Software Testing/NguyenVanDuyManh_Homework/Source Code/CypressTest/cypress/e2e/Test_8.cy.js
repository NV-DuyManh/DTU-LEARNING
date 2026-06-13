describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 8: a=50, b=-10001, c=50 <=> 50x² - 10001x + 50 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('50');
    cy.get('#term-b').clear().type('-10001');
    cy.get('#term-c').clear().type('50');
    cy.get('#root-1').should('have.value', 'Infinity');
    cy.get('#root-2').should('have.value', 'Infinity');
    cy.get('#delta').should('have.value', 'Infinity');
  });
});