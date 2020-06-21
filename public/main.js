Module.onRuntimeInitialized = () => {
  const canvas = document.querySelector("canvas");
  const context = canvas.getContext("2d");
  let canvasWei = canvas.width;
  let canvasHei = canvas.height;
  _generateCircles();
  let circles = [];
  const circleGenerator = (i) => {
    context.beginPath();
    context.arc(
      circles[i],
      circles[i + 1],
      circles[i + 2],
      0,
      2 * Math.PI,
      false
    );
    context.fillStyle = `rgb(${circles[i + 3]},${circles[i + 4]},${
      circles[i + 5]
    })`;
    context.fill();
  };
  const render = () => {
    context.clearRect(0, 0, canvasWei, canvasHei);
    circles = new Int32Array(
      Module.HEAP32.buffer,
      _getCircles(canvasWei, canvasHei),
      6 * 500
    );
    for (let i = 0; i < circles.length; i += 6) {
      circleGenerator(i);
    }
    window.requestAnimationFrame(() => {
      render();
    });
  };
  render();
};
