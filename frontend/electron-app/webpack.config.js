const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = {
    mode: 'development',
    entry: './src/index.js',
    output: {
        path: path.resolve(__dirname, 'dist'),
        filename: 'bundle.js',
    },
    devServer: {
        static: path.join(__dirname, 'public'), // Serve static files (optional)
        hot: true,
        port: 3000,               // Ensure Electron loads from this port
        historyApiFallback: true, // Needed for React Router
    },
    module: {
        rules: [
            {
                test: /\.(js|jsx)$/,
                exclude: /node_modules/,
                use: {
                    loader: 'babel-loader',
                    options: {
                        presets: ['@babel/preset-react'],
                    },
                },
            },
            {
                test: /\.css$/,
                use: ['style-loader', 'css-loader'],
            },
        ],
    },
    resolve: {
        extensions: ['.js', '.jsx'], // Allow imports without file extensions
    },
    plugins: [
        new HtmlWebpackPlugin({
            template: './public/index.html', // Ensures index.html is generated correctly
        }),
    ],
};