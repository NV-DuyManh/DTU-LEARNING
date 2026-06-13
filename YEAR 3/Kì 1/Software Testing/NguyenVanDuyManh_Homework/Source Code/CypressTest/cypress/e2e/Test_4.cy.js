describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 4: a=0, b=50, c=50 <=> 0x² + 50x + 50 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('0');
    cy.get('#term-b').clear().type('50');
    cy.get('#term-c').clear().type('50');
    cy.get('#root-1').should('have.value', '-1.00');
    cy.get('#root-2').should('have.value', '—');
    cy.get('#delta').should('have.value', '—');
  });
});