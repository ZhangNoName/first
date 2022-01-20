import Vue from 'vue'
import App from './App.vue'
//import "tailwindcss/tailwind.css"
import ElementUI from 'element-ui'
import 'element-ui/lib/theme-chalk/index.css'
import router from './router/index.js'
import debounce from './directives/Throttle'
import BaseLayout from './components/BaseLayout/index.vue'
import loadMore from './directives/loadMore'
import './assets/common.css'
// import particlesJS from '../src/components/bgc-animate/bgc'

Vue.config.productionTip = false//禁止浏览器弹出优化提示

Vue.use(ElementUI);
Vue.use(debounce);
Vue.use(loadMore)
Vue.component('BaseLayout', BaseLayout)

new Vue({
  router,
  render: h => h(App),
}).$mount('#app')
