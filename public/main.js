Module.onRuntimeInitialized = () => {
  const canvas = document.querySelector("canvas");
  const context = canvas.getContext("2d");
  context.beginPath();
  context.arc(500, 500, 50, 0, 2 * Math.PI, false);
  context.fillStyle = "red";
  context.fill();
};
