describe('Quadratic Equation Test', () => {
  const baseUrl = 'http://127.0.0.1:5500/index.html';
  it('Case 3: a=-9999, b=50, c=50 <=> -9999x² + 50x + 50 = 0', () => {
    cy.visit(baseUrl);
    cy.get('#term-a').clear().type('-9999');
    cy.get('#term-b').clear().type('50');
    cy.get('#term-c').clear().type('50');
    cy.get('#root-1').should('have.value', '0.07');
    cy.get('#root-2').should('have.value', '-0.07');
    cy.get('#delta').should('have.value', '2002300.00');
  });
});