import Vue from 'vue'
import App from './App.vue'
import "tailwindcss/tailwind.css"
import ElementUI from 'element-ui'
import 'element-ui/lib/theme-chalk/index.css'
import VueRouter from 'vue-router'
import debounce from './directives/Throttle'
Vue.config.productionTip = false
Vue.use(ElementUI);
Vue.use(VueRouter);
Vue.use(debounce);
new Vue({
  render: h => h(App),
}).$mount('#app')
