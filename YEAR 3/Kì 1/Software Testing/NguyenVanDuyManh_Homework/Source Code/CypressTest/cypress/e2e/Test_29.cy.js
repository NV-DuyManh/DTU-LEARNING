describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 29: a=0, b=2, c=5 <=> 0x² + 2x + 5 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('0');
    cy.get('#term-b').clear().type('2');
    cy.get('#term-c').clear().type('5');
    cy.get('#root-1').should('have.value', '-2.5');
    cy.get('#root-2').should('have.value', '—');
    cy.get('#delta').should('have.value', '—');
  });
});