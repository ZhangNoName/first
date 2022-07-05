// import { defineConfig } from 'vite';
import { createVuePlugin } from 'vite-plugin-vue2';
import tsconfigPaths from 'vite-tsconfig-paths';
// import eslintPlugin from 'vite-plugin-eslint'
// export default defineConfig({
//   plugins: [
//     //
//     createVuePlugin(),
//     tsconfigPaths(),
//   ],
// })
import { defineConfig,loadEnv } from 'vite'
const path = require("path");
export default ({ mode }) => {

    const isPro = mode === 'production' // 我们可以通过mode直接判断当前是不是生产环境，注意mode可以在运行指令中指定：`vite build --mode master`，如果没有指定，那默认打包就是production
    
    function getEnv(key) { // 定义获取环境变量的方法
        return loadEnv(mode, process.cwd(),'')[key] // 第三个参数非常重要，下面有详解
    }
    
    return defineConfig({
        base: getEnv('VUE_APP_PUBLICPATH'), // 读取环境变量
        plugins: [
            //
            createVuePlugin(),
            tsconfigPaths(),
        ],
        //修改alias别名配置，以及忽略文件后缀
        resolve: {
            alias: [
                { find: /^~@/, replacement: path.resolve(__dirname,'src') },
                { find: 'vue$', replacement: 'vue/dist/vue.esm.js' },
                { find: '@', replacement: path.resolve(__dirname,'src') },
                { find: '_PUBLIC_', replacement: path.resolve(__dirname,'src/public') },
                { find: '_PAGES_', replacement: path.resolve(__dirname,'src/page') },
                { find: '_COMP_', replacement: path.resolve(__dirname,'src/public/components') }
            ],
            extensions: ['.mjs', '.js', '.ts', '.jsx', '.tsx', '.json', '.vue', '.less'] // 需要忽略的文件后缀
        },
        
    })
}