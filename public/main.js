Module.onRuntimeInitialized = () => {
  const canvas = document.querySelector("canvas");
  const context = canvas.getContext("2d");
  const circle = [];
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
  const render = (num) => {
    circles = new Int32Array(Module.HEAP32.buffer, _getCircle(num), 6 * num);
    for (let i = 0; i < circles.length; i += 6) {
      circleGenerator(i);
    }
  };
  render(10);
};
