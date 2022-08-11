import { useDispatch, useSelector } from "../../../node_modules/react-redux/es/exports"
import { logout } from "../../modules/user";
import Header from "./Header";

const HeaderContainer = () => {
  const {user} = useSelector(({user}) => ({user: user.user}));
  const dispatch = useDispatch();
  const onLogout = () => {
    dispatch(logout());
  };
  return <Header user={user} onLogout={onLogout}/>;
};

export default HeaderContainer;