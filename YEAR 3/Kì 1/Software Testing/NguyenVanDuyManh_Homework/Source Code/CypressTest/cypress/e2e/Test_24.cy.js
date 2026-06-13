describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 24: a=0, b=0, c=0 <=> 0x² + 0x + 0 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('0');
    cy.get('#term-b').clear().type('0');
    cy.get('#term-c').clear().type('0');
    cy.get('#root-1').should('have.value', '∞');
    cy.get('#root-2').should('have.value', '∞');
    cy.get('#delta').should('have.value', '—');
  });
});