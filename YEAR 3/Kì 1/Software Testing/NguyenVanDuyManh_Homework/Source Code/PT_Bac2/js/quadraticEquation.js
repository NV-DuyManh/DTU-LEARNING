function quadraticEquation() {

  const inputTermA = document.querySelector('#term-a');
  const inputTermB = document.querySelector('#term-b');
  const inputTermC = document.querySelector('#term-c');
  const inputRoot1 = document.querySelector('#root-1');
  const inputRoot2 = document.querySelector('#root-2');
  const inputDelta = document.querySelector('#delta');

  const CUSTOM_LIMIT = 10000;

  let termA = parseFloat(inputTermA.value || 0) ;
  let termB = parseFloat(inputTermB.value || 0) ;
  let termC = parseFloat(inputTermC.value || 0) ;

  if (
    Math.abs(termA) > CUSTOM_LIMIT || 
    Math.abs(termB) > CUSTOM_LIMIT || 
    Math.abs(termC) > CUSTOM_LIMIT
  ) {
    
    inputDelta.value = 'Infinity';
    inputRoot1.value = 'Infinity';
    inputRoot2.value = 'Infinity';
    return; 
  }

  inputTermA.style.color = '#576574';
 
  if (termA === 0) {
    inputDelta.value = '—';
    if (termB === 0) {
      if (termC === 0) {
        inputRoot1.value = '∞';
        inputRoot2.value = '∞';
      } else {
        inputRoot1.value = '∅';
        inputRoot2.value = '∅';
      }
    } else {
      const x = -termC / termB;
      inputRoot1.value = x;
      inputRoot2.value = '—';
    }
    return;
  }

  const termDelta = termB ** 2 - 4 * termA * termC;
  if (!isFinite(termDelta)) {
    inputDelta.value = 'ERROR';
    inputRoot1.value = 'ERROR';
    inputRoot2.value = 'ERROR';
    return;
  }
  inputDelta.value = termDelta.toFixed(2);

  if (termDelta > 0) {
    const x1 = (-termB - Math.sqrt(termDelta)) / (2 * termA);
    const x2 = (-termB + Math.sqrt(termDelta)) / (2 * termA);
    inputRoot1.value = x1.toFixed(2);
    inputRoot2.value = x2.toFixed(2);
  } else if (termDelta === 0) {
    const x = -termB / (2 * termA);
    inputRoot1.value = x.toFixed(2);
    inputRoot2.value = x.toFixed(2);
  } else {
    const realPart = (-termB / (2 * termA)).toFixed(2);
    const imaginaryPart = Math.abs(Math.sqrt(Math.abs(termDelta)) / (2 * termA)).toFixed(2);
    inputRoot1.value = `${realPart} - ${imaginaryPart}i`;
    inputRoot2.value = `${realPart} + ${imaginaryPart}i`;
  }
}
