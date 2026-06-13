describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 27: a=4, b=2, c=8 <=> 4x² + 2x + 8 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('4');
    cy.get('#term-b').clear().type('2');
    cy.get('#term-c').clear().type('8');
    cy.get('#root-1').should('have.value', '-0.25 - 1.39i');
    cy.get('#root-2').should('have.value', '-0.25 + 1.39i');
    cy.get('#delta').should('have.value', '-124.00');
  });
});