import Vue from 'vue'
import Router from 'vue-router'


Vue.use(Router)

const router = new Router({
  routes : [
    {
      path : '/',
      redirect : '/index'
    },
    {
      path : '/index',
      name : '主页',
      component : () => import('@/views/test/index.vue'),
      children : []
    },
  ]
})

router.beforeEach((to, from, next) => {
  // console.log(to)
  // console.log(from)
  next()
})

export default router