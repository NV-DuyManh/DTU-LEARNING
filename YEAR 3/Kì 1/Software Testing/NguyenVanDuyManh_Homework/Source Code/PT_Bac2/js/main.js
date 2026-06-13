const terms = document.querySelectorAll('.terms');

terms.forEach(el =>
  el.addEventListener('input', () => {
    quadraticEquation();
  })
);
