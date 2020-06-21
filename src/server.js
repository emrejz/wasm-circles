const express = require("express");
const app = express();

app.use(
  express.static("public", {
    setHeaders: (res, path, stat) => {
      if (path.endsWith(".wasm")) {
        res.setHeader("Content-Type", "application/wasm");
      }
    },
  })
);

app.listen(3000, () => console.log("server ok"));
