const { defineConfig } = require("cypress");

module.exports = defineConfig({
  projectId: "h2mc2j",
  e2e: {
    baseUrl: "http://127.0.0.1:5500",
    setupNodeEvents(on, config) {
      // có thể thêm event ở đây nếu cần
    },
  },
  reporter: "mochawesome",
  reporterOptions: {
    reportDir: "cypress/reports",
    overwrite: false,
    html: true,
    json: true,
  },
});
