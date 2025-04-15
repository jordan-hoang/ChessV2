const { app, BrowserWindow } = require('electron');
const path = require('path');

//
// This is Electron main process!
//

function createWindow() {
    const win = new BrowserWindow({
        width: 1200,
        height: 1200,
        webPreferences: {
            nodeIntegration: true,
        },
    });

    // Point to the React development server
    win.loadURL('http://localhost:3000');  // Make sure this is the correct URL as REACT
    win.webContents.openDevTools(); // Open DevTools to debug
}

app.whenReady().then(createWindow);

// This stuff here is just for MAC.
app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
        app.quit();
    }
});