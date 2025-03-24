import React from 'react';
import ReactDOM from 'react-dom/client';
import App from './App';  // The main app component


// Responsible for rendering the APP component into the dom.
// renders it into a div.
// Basically connects your React APPLICATION to your dom.
// RARELY MODIFIED.

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
    <React.StrictMode>
        <App />
    </React.StrictMode>,
);