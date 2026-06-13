describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 42: a=1, b="3.1.2004", c=2 <=> 1x² + "3.1.2004"x + 2 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('1');
    cy.get('#term-b').clear().type('3.1.2004');
    cy.get('#term-c').clear().type('2');
    cy.get('#root-1').should('have.value', 'ERROR');
    cy.get('#root-2').should('have.value', 'ERROR');
    cy.get('#delta').should('have.value', 'ERROR');
  });
});