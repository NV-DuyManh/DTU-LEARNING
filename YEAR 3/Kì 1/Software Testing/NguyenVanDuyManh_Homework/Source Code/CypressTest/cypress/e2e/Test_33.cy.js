describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 33: a=abc, b=5, c=1 <=> "abc"x² + 5x + 1 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('abc');
    cy.get('#term-b').clear().type('5');
    cy.get('#term-c').clear().type('1');
    cy.get('#root-1').should('have.value', 'ERROR');
    cy.get('#root-2').should('have.value', 'ERROR');
    cy.get('#delta').should('have.value', 'ERROR');
  });
});