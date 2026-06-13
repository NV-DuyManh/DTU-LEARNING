describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 45: a="", b="", c="" <=> ""x² + ""x + "" = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear();
    cy.get('#term-b').clear();
    cy.get('#term-c').clear();
    cy.get('#root-1').should('have.value', 'ERROR');
    cy.get('#root-2').should('have.value', 'ERROR');
    cy.get('#delta').should('have.value', 'ERROR');
  });
});